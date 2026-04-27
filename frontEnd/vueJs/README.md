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


## 4.27
浏览器解释vue项目的执行顺序 ： 
   1. index.html
   提供页面容器
   ```
   <div id="app"></div>
   ```
   浏览器把vue项目渲染到id="app"标签中

   2. main.js
   创建vue实例，把根组件挂载到页面
   ```
   import { createApp } from 'vue'
   import App from './App.vue'

   createApp(App).mount('#app')
   ```
   3. App.vue
   整个项目的最外层页面结构
   ```
   <template>
   <div>
      <h1>Hello Vue!</h1>
   </div>
   </template>
   ```
   所有页面内容从这里开始显示
   4. HelloWorld.vue
   被调用App.vue调用
   ```
   <template>
   <div>
      这是子组件内容
   </div>
   </template>
   ```

#### 类比java项目
index是main函数
main.js是创建对象（比如创建学生类）
app.vue是类的属性（比如学生类，包含姓名年龄...）

