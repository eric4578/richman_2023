import sys

def compare_files(file1, file2):
    with open(file1, 'r') as f1, open(file2, 'r') as f2:
        text1 = f1.read()
        text2 = f2.read()
    
    output = ''
    for char1, char2 in zip(text1, text2):
        if repr(char1) != repr(char2):
            output += '\033[91m' + char2 + '\033[0m'
        else:
            output += char2
    
    return output

if len(sys.argv) < 3:
    print("请提供两个文件路径作为命令行参数。")
    sys.exit(1)

file1 = sys.argv[1]
file2 = sys.argv[2]

output = compare_files(file1, file2)
print(output)