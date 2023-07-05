import subprocess
import concurrent.futures
import random
import os
import sys
import platform
from colorama import Fore, Style
from functools import wraps


class Test:
    def __init__(self, filePath:str, testName:str = "", testNum:int = 0, hasIllegal:bool = False, ErrorRate:float = 0.05, TestCasePath:str = "") -> None:
        self._tests = []
        self._filePath = filePath
        self._TestOutPath = filePath + "/TestCase_Print"
        self._testName = testName
        self._testNum = testNum # test tasks num
        self._hasIllegal = hasIllegal # whether the program generated illegal data
        self._ErrorRate = ErrorRate # if illegal data is generated, the probability of illegal data generation
        self._weights = [1 - ErrorRate, ErrorRate]
        self._results = None # task results
        self._testCasePath = TestCasePath
        self._AllCasePath = []
        self._colors = [Fore.LIGHTGREEN_EX, Fore.RED, Fore.BLUE, Style.RESET_ALL, Fore.MAGENTA, Fore.CYAN] # ANSI color: front_green, front_red, front_blue, front_reset, front_magenta, front_cyan
        self.__default_tests()
        self._successNum = 0 # success test num
        self._system = platform.system()

        if not os.path.exists(self._filePath):
            self.__print_error_info(self, "Fail to open file!")
            exit(1)

    def set_tests(self, tests:str) -> None: # customize test
        self._tests = tests
    
    def __read_cases_files(self, _path:str):
        for file in os.listdir(_path):
            file_path = os.path.join(_path, file)
            if os.path.isdir(file_path):
                self.__read_cases_files(file_path)
            else:
                self._AllCasePath.append(file_path)

    def read_test_case(self, TestCasePath:str = "") -> tuple[bool, int]:
        if self._testCasePath == "" and TestCasePath == "":
            self.__print_error_info(self, "Path does not exist!")
            return False, 0
        else:
            if TestCasePath != "":
                self._testCasePath = TestCasePath
                
            self.__read_cases_files(self._testCasePath)

            self._tests = []
            already_read = []
            for i in self._AllCasePath:
                f_dict = {"path":"", "input":[], "expected_output": ""}
                file_name, extension = os.path.splitext(i)

                if extension != '.in' and extension != '.out':
                    continue

                if file_name in already_read:
                    continue

                if '_r' in file_name:
                    continue
                
                f_dict["path"] = file_name + "_r.out"
                with open(file_name + '.in', 'r') as in_file:
                    f_dict["input"] = in_file.readlines()
                with open(file_name + '.out', 'r') as out_file:
                    f_dict["expected_output"] = ''.join(out_file.readlines())

                self._tests.append(f_dict)
                already_read.append(file_name)

            self._testNum = len(self._tests)
            return True, self._testNum

    def set_test_name(self, testName:str):
        self._testName = testName

    def get_test_name(self) -> str:
        return self._testName

    def __default_tests(self) -> None:
        self._tests = [
            {"path":"", "input":[], "expected_output":""}
        ]

    def __print_test_name(_end:str='') -> None: # print test name
        def _print(print_func):
            @wraps(print_func)
            def warp(self, *args, **kwargs):
                print(f'[{self._colors[2]}{self._testName}{self._colors[3]}]', end=_end)
                print_func(*args, **kwargs)
            return warp
        return _print
    
    @__print_test_name()
    def __print_finish_info(self) -> None:
        print(f'{self._colors[0]}Test finished!{self._colors[3]} Total:{self._testNum}, Success:{self._successNum}, Fail:{self._testNum - self._successNum}{self._colors[3]}')

    @__print_test_name()
    def __print_pass_info(self) -> None:
        print(f'{self._colors[0]}Test passed!{self._colors[3]}')

    @__print_test_name()
    def __print_fail_info(self, _input:list, _expected:str, _actual:str) -> None:
        print(f'{self._colors[1]}Test failed! input:{_input}, expected_output:{repr(_expected)}, actual_output:{repr(_actual)}{self._colors[3]}')

    @__print_test_name()
    def __print_error_info(self, msg:str) -> None:
        print(f"{self._colors[4]}{msg}{self._colors[3]}")

    @__print_test_name()
    def __print_warn_info(self, msg:str) -> None:
        print(f"{self._colors[5]}{msg}{self._colors[3]}")

    def __gen_input(self) -> None: # generate special test input
        pass

    def __gen_expected_output(self) -> None: # generate special test expected output
        pass

    def gen_test(self) -> None: # generate special test
        pass

    def compare_str(self, str1:str, str2:str) -> tuple[bool, str]: # find the difference of str1, str2
        if str1 == str2:
            return True, []
        
        output = ""
        i = 0
        for char1, char2 in zip(str1, str2):
            if char1 == char2:
                output += char1
            else:
                output += f"{self._colors[1]}{char2}{self._colors[3]}"
            i += 1

        if i < len(str2):
            output += [_ for _ in range(i, len(str2))]
        
        return False, output

    def __run_test(self, _data:list) -> str: # run single test
        p = subprocess.Popen([self._filePath, _data["path"]], stdin=subprocess.PIPE, stdout=subprocess.PIPE)

        try:
            for i, item in enumerate(_data["input"]):
                p.stdin.write((item + '\n').encode())
                p.stdin.flush()

            _stdout, _ = p.communicate()
            p.stdin.close()
            p.stdout.close()

            _dump_out = ""
            with open(_data["path"], 'r') as out_obj:
                _dump_out = ''.join(out_obj.readlines())

            return _dump_out
        except BrokenPipeError:
            self.__print_warn_info(self, "Running warn:[BrokenPipeError]. Other tasks not terminated!")
            return ""

    def create_test_tasks(self, parallel:bool = False, concise:bool = False) -> None: # create test tasks, tesk num = self._testNum
        self._successNum = 0

        if parallel:
            with concurrent.futures.ThreadPoolExecutor() as executor:
                self._results = executor.map(self.__run_test, [test for test in self._tests])
                self._results = list(self._results)
        else:
            self._results = [self.__run_test(_) for _ in self._tests]

        for test, output in zip(self._tests, self._results):
            if output == test["expected_output"]:
                self._successNum += 1

                if concise:
                    continue
                
                self.__print_pass_info(self)
            else:
                self.__print_fail_info(self, test["input"], test["expected_output"] ,output)

        self.__print_finish_info(self)


class TestUnitTest(Test):
    '''
    unit test test
    Test whether the unit test module is normal.
    '''

    def __init__(self, filePath:str, testNum:int = 0, hasIllegal:bool = False, ErrorRate:float = 0.05, TestCasePath:str = "") -> None:
        super().__init__(filePath, "TestUnitTest", testNum, hasIllegal, ErrorRate, TestCasePath)
        self.__default_tests()
        if not hasIllegal:
            self._weights = [1, 0]
            self._ErrorRate = 0

    
    def __default_tests(self) -> None:
        self._tests = [
            {"path":f"./dump.out", "input":["1", "50", "0"], "expected_output": "1\n50\n0\n"},
        ]

    def gen_test(self) -> None:
        self._tests = []

        for i in range(self._testNum):
            rinta = str(random.randint(1, 10))
            rintb = str(random.randint(1, 10))
            rintc = str(random.randint(1, 10))
            self._tests.append({})
            self._tests[i] = {"path":f"./dump.out", "input": [rinta, rintb, rintc], "expected_output": rinta + ' ' + rintb + ' ' + rintc + '\n'}


class TestPointStore(Test): # test for point store
    '''
    point store test
    input:one purchase operation, format: operation present_points present_item_num
    output: ["点数不足，退出道具房\n", "退出道具房\n", "道具已满\n", "已购买xxx\n", f"已购买xxx\n点数不足，退出道具房\n", "非法输入\n", "点数不足，购买失败\n"]
    example: input:['1', '50', '0'], expected_output:['已购买路障\n点数不足，退出道具房\n']
    '''

    def __init__(self, filePath:str, testNum:int = 0, hasIllegal:bool = False, ErrorRate:float = 0.05, TestCasePath:str = "") -> None:
        super().__init__(filePath, "TestPointStore", testNum, hasIllegal, ErrorRate, TestCasePath)
        self.__default_tests()
        if not hasIllegal:
            self._weights = [1, 0]
            self._ErrorRate = 0

    def __default_tests(self) -> None:
        self._tests = [
            {"path":"", "input":["1", "50", "0"], "expected_output":"已购买路障\n点数不足，退出道具房\n"},
        ]
    
    def gen_test(self) -> None: # generate special test
        self.__gen_input()
        self.__gen_expected_output()

    def __gen_input(self) -> None:
        self.tools = [['1', '2', '3'], ['-1', '0', '4', '1.23', '3.44']]
        self.quit = [['F', 'f'], ['a', 'b', '#', 'q', '@']]
        self.points = [(0, 200), (-5, -1)]
        self.tools_num = [(0, 10), (-5, -1), (11, 15)]

        self._tests = []
        for i in range(self._testNum):
            self._tests.append({})
            input = ""

            # there is a 60% probability of generating numbers and a 40% probability of generating 'f'
            if random.uniform(0, 1) > 0.4: 
                tools_range = random.choices(self.tools, self._weights)[0]
                input = random.choice(tools_range)
            else:
                quit_range = random.choices(self.quit, self._weights)[0]
                input = random.choice(quit_range)

            # generate points
            points_range = random.choices(self.points, self._weights)[0]
            points = random.randint(*points_range)

            # generate the number of tools
            tools_num_range = random.choices(self.tools_num, [1 - self._ErrorRate, 0.5 * self._ErrorRate, 0.5 * self._ErrorRate])[0]
            tools_number = random.randint(*tools_num_range)

            self._tests[i]["input"] = [input, str(points), str(tools_number)]
            self._tests[i]["path"] = ""
    
    def __gen_expected_output(self) -> None:
        self._point = [50, 30, 50]
        self._item = ["路障", "机器娃娃", "炸弹"]

        for test in self._tests:
            if int(test["input"][1]) < 30: # insufficient points, exiting the store
                test["expected_output"] = "点数不足，退出道具房\n"
            elif test["input"][0].lower() == 'f': # input 'f'
                test["expected_output"] = "退出道具房\n"
            elif len(test["input"][0]) == 1 and test["input"][0].isdigit(): # input 1 or 2 or 3
                if int(test["input"][2]) >= 10: # full item
                    test["expected_output"] = "道具已满\n"
                elif 0 <= int(test["input"][2]) < 10: # can buy item
                    if int(test["input"][1]) - self._point[int(test["input"][0]) - 1] >= 30: 
                        # sufficient points and remaining after purchase
                        test["expected_output"] = f"已购买{self._item[int(test['input'][0]) - 1]}\n"
                    elif 30 > int(test["input"][1]) - self._point[int(test["input"][0]) - 1] >= 0: 
                        # Enough points, but not enough to buy again after purchase, automatic exit
                        test["expected_output"] = f"已购买{self._item[int(test['input'][0]) - 1]}\n点数不足，退出道具房\n"
                    else:
                        test["expected_output"] = "点数不足，购买失败\n"
            else:
                test["expected_output"] = "非法输入\n"
            

class NormalTest(Test):
    def __init__(self, filePath:str, testName:str="", testNum:int = 0, hasIllegal:bool = False, ErrorRate:float = 0.05, TestCasePath:str = "") -> None:
        super().__init__(filePath, testName, testNum, hasIllegal, ErrorRate, TestCasePath)
        self.__default_tests()
        if not hasIllegal:
            self._weights = [1, 0]
            self._ErrorRate = 0

    def __default_tests(self) -> None:
        self._tests = [
            {"path":"", "input":[], "expected_output":""}
        ]


def _test(path:str) -> None:
    os.system(f"gcc ./{path}/UnitTestExample/Example.c -o ./{path}/UnitTestExample/Example")
    _test = TestUnitTest(filePath=f"./{path}/UnitTestExample/Example", testNum=3)
    _test.gen_test()
    _test.create_test_tasks(concise=True)
    _test.read_test_case(TestCasePath=f"./{path}/UnitTestExample")
    _test.create_test_tasks(concise=True)
    os.system(f"rm ./{path}/UnitTestExample/Example")
    os.system(f"rm ./dump.out")
    os.system(f"rm {_test._testCasePath}/Example_r.out")


def SingleCommandTest(program_path:str, case_path:str) -> None:
    _path = f"{case_path}/SingleCommand/"
    test_content = {"dump": "TestDump", "init": "TestInit", "set": "TestSet", "step": "TestStep", }
    for key, value in test_content.items():
        test_content[key] = NormalTest(filePath=program_path, testName=value, TestCasePath=_path + key)
        test_content[key].read_test_case()


        
def main():
    if len(sys.argv) != 3:
        print('python UnitTest.py main TestCase_dir')
        return
    program_path = sys.argv[1]
    case_path = sys.argv[2][:-1] if sys.argv[2].endswith('/') else sys.argv[2]

    _test(case_path)

    SingleCommandTest(program_path=program_path, case_path=case_path)
    

if __name__ == '__main__':
    main()