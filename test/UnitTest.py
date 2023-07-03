import subprocess
import concurrent.futures
import random
import os
from colorama import Fore, Style

class Test:
    def __init__(self, filePath:str, testName:str, testNum: int, hasIllegal:bool = False, ErrorRate:float = 0.05) -> None:
        self._tests = []
        self._filePath = filePath
        self._testName = testName
        self._testNum = testNum # test tasks num
        self._hasIllegal = hasIllegal # whether the program generated illegal data
        self._ErrorRate = ErrorRate # if illegal data is generated, the probability of illegal data generation
        self._weights = [1 - ErrorRate, ErrorRate]
        self._results = None # task results
        self._colors = [Fore.GREEN, Fore.RED, Fore.BLUE, Style.RESET_ALL, Fore.YELLOW] # ANSI color: front_green, front_red, front_blue, front_reset, front_yellow
        self.__default_tests()
        self._successNum = 0 # success test num

        if not os.path.exists(self._filePath):
            self.__print_test_name()
            print(f"{self._colors[1]}Fail to open file!{self._colors[3]}")
            exit(1)

    def set_tests(self, tests:str) -> None: # customize test
        self._tests = tests

    def __default_tests(self) -> None:
        self._tests = [
            {"input":[], "expected_output":""}
        ]

    def __print_test_name(self, _end='') -> None: # print test name
        print(f'[{self._colors[2]}{self._testName}{self._colors[3]}]', end=_end)

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

    def __run_test(self, input_data:list) -> str: # run single test
        p = subprocess.Popen([self._filePath], stdin=subprocess.PIPE, stdout=subprocess.PIPE)

        try:
            for i, item in enumerate(input_data):
                p.stdin.write((item + '\n').encode())
                p.stdin.flush()

            _stdout, _ = p.communicate()
            p.stdin.close()
            p.stdout.close()

            return _stdout.decode()
        except BrokenPipeError:
            self.__print_test_name()
            print(f"{self._colors[4]}Run test error:[BrokenPipeError]. Other tests not terminated!{self._colors[3]}")
            return ""

    def create_test_tasks(self) -> None: # create test tasks, tesk num = self._testNum
        self._successNum = 0

        with concurrent.futures.ThreadPoolExecutor() as executor:
            self._results = executor.map(self.__run_test, [test["input"] for test in self._tests])

        for test, output in zip(self._tests, self._results):
            self.__print_test_name()
            if output == test["expected_output"]:
                self._successNum += 1
                print(f'{self._colors[0]}Test passed!{self._colors[3]}')
            else:
                print(f'{self._colors[1]}Test failed! input:{test["input"]}, expected_output:{repr(test["expected_output"])}, actual_output:{repr(output)}{self._colors[3]}')
        
        self.__print_test_name()
        print(f'{self._colors[0]}Test finished!{self._colors[3]} Total:{self._testNum}, Success:{self._successNum}, Fail:{self._testNum - self._successNum}{self._colors[3]}')

class TestUnitTest(Test):
    '''
    unit test test
    Test whether the unit test module is normal.
    '''

    def __init__(self, filePath:str, testNum: int, hasIllegal:bool = False, ErrorRate:float = 0.05) -> None:
        super().__init__(filePath, "TestUnitTest", testNum, hasIllegal, ErrorRate)
        self.__default_tests()
        if not hasIllegal:
            self._weights = [1, 0]
            self._ErrorRate = 0

    
    def __default_tests(self) -> None:
        self._tests = [
            {"input":["1", "50", "0"], "expected_output": "1\n50\n0\n"},
        ]

    def gen_test(self) -> None:
        self._tests = []

        for i in range(self._testNum):
            rinta = str(random.randint(1, 10))
            rintb = str(random.randint(1, 10))
            rintc = str(random.randint(1, 10))
            self._tests.append({})
            self._tests[i] = {"input": [rinta, rintb, rintc], "expected_output": rinta + '\n' + rintb + '\n' + rintc + '\n'}



class TestPointStore(Test): # test for point store
    '''
    point store test
    input:one purchase operation, format: operation present_points present_item_num
    output: ["点数不足，退出道具房\n", "退出道具房\n", "道具已满\n", "已购买xxx\n", f"已购买xxx\n点数不足，退出道具房\n", "非法输入\n", "点数不足，购买失败\n"]
    example: input:['1', '50', '0'], expected_output:['已购买路障\n点数不足，退出道具房\n']
    '''

    def __init__(self, filePath:str, testNum: int, hasIllegal:bool = False, ErrorRate:float = 0.05) -> None:
        super().__init__(filePath, "TestPointStore", testNum, hasIllegal, ErrorRate)
        self.__default_tests()
        if not hasIllegal:
            self._weights = [1, 0]
            self._ErrorRate = 0

    def __default_tests(self) -> None:
        self._tests = [
            {"input":["1", "50", "0"], "expected_output":"已购买路障\n点数不足，退出道具房\n"},
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
            

class TestDice(Test):
    def __init__(self, filePath:str, testNum: int, hasIllegal:bool = False, ErrorRate:float = 0.05) -> None:
        super().__init__(filePath, "TestDice", testNum, hasIllegal, ErrorRate)
        self.__default_tests()
        if not hasIllegal:
            self._weights = [1, 0]
            self._ErrorRate = 0

    def __default_tests(self) -> None:
        self._tests = [
            {"input":[], "expected_output":""}
        ]


class TestMap(Test):
    def __init__(self, filePath:str, testNum: int, hasIllegal:bool = False, ErrorRate:float = 0.05) -> None:
        super().__init__(filePath, "TestMap", testNum, hasIllegal, ErrorRate)
        self.__default_tests()
        if not hasIllegal:
            self._weights = [1, 0]
            self._ErrorRate = 0

    def __default_tests(self) -> None:
        self._tests = [
            {"input":[], "expected_output":""}
        ]


class TestBuyLand(Test):
    def __init__(self, filePath:str, testNum: int, hasIllegal:bool = False, ErrorRate:float = 0.05) -> None:
        super().__init__(filePath, "TestBuyLand", testNum, hasIllegal, ErrorRate)
        self.__default_tests()
        if not hasIllegal:
            self._weights = [1, 0]
            self._ErrorRate = 0

    def __default_tests(self) -> None:
        self._tests = [
            {"input":[], "expected_output":""}
        ]


class TestSellingLand(Test):
    def __init__(self, filePath:str, testNum: int, hasIllegal:bool = False, ErrorRate:float = 0.05) -> None:
        super().__init__(filePath, "TestSellingLand", testNum, hasIllegal, ErrorRate)
        self.__default_tests()
        if not hasIllegal:
            self._weights = [1, 0]
            self._ErrorRate = 0

    def __default_tests(self) -> None:
        self._tests = [
            {"input":[], "expected_output":""}
        ]
        


if __name__ == '__main__':
    a = TestUnitTest("./UnitTestExample", 5)
    a.gen_test()
    a.create_test_tasks()

    # point store test
    # input:one purchase operation, format: operation present_points present_item_num
    # output: ["点数不足，退出道具房\n", "退出道具房\n", "道具已满\n", "已购买xxx\n", f"已购买xxx\n点数不足，退出道具房\n", "非法输入\n", "点数不足，购买失败\n"]
    # example: input:['1', '50', '0'], expected_output:['已购买路障\n点数不足，退出道具房\n']
    

    # create default tasks
    # the tasks' details, plz see __default_tests function overloading
    test_store = TestPointStore("./UnitTestExample", 1)
    test_store.create_test_tasks()

    # create 10 random tasks
    # randomly generated tasks may have poor quality
    test_store = TestPointStore("./UnitTestExample", 10)
    test_store.gen_test()
    test_store.create_test_tasks()


    test_store = TestPointStore("./Unaaample", 10)
