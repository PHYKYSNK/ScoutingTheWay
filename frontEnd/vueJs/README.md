### 4.20 
下载了一些必要软件，进行环境配置。两种方式创建项目。

1. 软件下载 ： 
   首先下载nodejs,官网地址如下，国内可下载
   https://nodejs.org/zh-cn
   这里的话npm也附带安装了
   然后输入指令下载yarn
   ```
   npm install -g yarn # 下载
   yarn config set registry https://registry.npmmirror.com # 镜像源换成国内的，速度快
   yarn config get registry  # 验证配置成功
   ```

2. 项目创建 ： 
    进入D盘
    ```
    mkdir 202412211304庞浩-0420 # 创建文件夹
    ```
    执行一系列操作npm创建完成
    ```
    npm create vite@latest 202412211304vite_npm -- --template vue  # 创建
    cd 202412211304vite_npm  # 进入
    npm install   # 下载依赖
    npm run dev   # 运行
    ```
    yarn 同理 
    ```
    yarn create vite 202412211304vite_yarn --template vue
    cd 202412211304vite_yarn
    yarn install
    yarn dev
    ```
    在命令行中找着运行就可以成功得到 
    http://localhost:5173/ 
    的端口号


    vscode使用同理,不多赘述。