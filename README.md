# ComputerVisionProject (基于Visual Studio 2026)

实验相关图片存于data/下


## 实验一

### 项目:Project1
### 配置项:
#### 项目属性(项目->属性)

1. 配置Release和Debug共有的配置

左上角 配置->选择:所有配置

配置属性::VC++目录->外部包含目录-><编辑> "D:\tools\opencv\build\include\" (头文件目录 设为:opencv安装目录\build\include)

配置属性::VC++目录->库目录-><编辑> "D:\tools\opencv\build\x64\vc16\lib\" (静态库目录 设为:opencv安装目录\build\x64\vc16\lib\)

配置属性::调试->环境-><编辑> "PATH=D:\tools\opencv\build\x64\vc16\bin;$(Path)" (启动调试时将opencv中dll目录加入环境变量,否则程序找不到opencv的dll文件将无法启动)

2. 配置静态链接库,此步骤Release和Debug不同

左上角 配置->选择:Debug

配置属性::链接器::输入->附加依赖项-><编辑> 'opencv_world4140d.lib'

左上角 配置->选择:Release

配置属性::链接器::输入->附加依赖项-><编辑> 'opencv_world4140.lib'

#### 代码修改

修改Project1.cpp的abslutePath为自己vs项目根目录

```cpp
//项目绝对路径 替换成自己的
const string abslutePath = "G:/Developer/repos/ComputerVisionProject/";
```


