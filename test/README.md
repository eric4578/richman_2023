# 测试说明

目前测试仅有点数商店测试

**指令：python UnitTest.py [可执行文件位置] [TestCase文件夹位置]**

## 测试样例编写

每个测试样例的输入和输出分别为名字相同但后缀不同的.in和.out文件，如ps1.in和ps1.out。

.in文件内为对被测试程序的标准输入，每一行为一次输入（可以理解为每输入一行就有一次回车）

.out文件内为测试对应的标准输出，需要包含换行

测试原理为通过子进程调用被测试程序，通过标准输入输出进行通信，将标准输出与预期进行比较，完全一致则测试通过。

## 注意事项

UnitTest.py会自动编译同一目录下的./UnitTestExample.c文件并测试UnitTest本身是否正常工作，测试结束后会删除编译生成的./UnitTestExample

测试点数商店：测试样例目录为TestCase/SingleFunction/PointStore