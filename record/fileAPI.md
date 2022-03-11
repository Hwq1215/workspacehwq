# 关于图像文件的API说明
## 目前项目属性如下
```java
public class DealingProject {
    private Integer id;         //项目编号
    private Integer lowPrice,highPrice; //价格
    private Integer amount;     //处理量
    private String imgPath;     //图片文件路径
    private String port;        //端口
    private String type;        //种类
    private String name;        //项目的名字
    private String demand;      //需求
    private String introduce;   //项目的内容
    private String location;    //项目的地域
    private Integer ripe;        //成熟度
    private String time ;       //项目开始时间
    private String tag1;         //标签1
    private String tag2;         //标签2
    private String tag3;         //标志3
    }
```
### 新增了图片文件路径"imgPath"这一属性。
```mysql
    在数据库内的存储标准格式如"\img\projects\1d2b9982d844411e9572ee63ad9d1f3b.bmp"
```
    
### 使用方法如下：
```html
  <!--直接从我这拿图片-->
    <img src="http://sanchuang.vaiwan.cn/img/projects/default.png"> 
    <!--记得在前面补域名-->
    <!--imgPath我没有补域名，是考虑通用性，如果你觉得麻烦可以再改-->
```
### 我写的上传测试用例，可以参考一下
```html
    <!--
        herf="http://sanchuang.vaiwan.cn"
        特别注意：表单的enctype属性，记得要这样写
    -->
    <!DOCTYPE html>
<html lang="en" xml:th="www.thymeleaf.org" xmlns="http://www.w3.org/1999/html" xmlns="http://www.w3.org/1999/html"
      xmlns="http://www.w3.org/1999/html" xmlns="http://www.w3.org/1999/html" xmlns="http://www.w3.org/1999/html"
      xmlns="http://www.w3.org/1999/html" xmlns="http://www.w3.org/1999/html" xmlns="http://www.w3.org/1999/html">
<head>
    <meta charset="UTF-8">
    <t2>增加项目</t2>
</head>
<body>
<form action="publish/summit"  method="post" enctype="multipart/form-data"> 
    <p>低价格: <input type="number" name="lowPrice" /></p>
    <p>高价格: <input type="number" name="highPrice" /></p>
    <p>数量: <input type="number" name="amount" /></p>
    <p>文件路径: <input type="file" name="img" /></p>
    <p>种类: <input type="text" name="type" /></p>
    <p>端口: <input type="text" name="port" /></p>
    <p>项目名字: <input type="text" name="name" /></p>
    <p>地域: <input type="text" name="location" /></p>
    <p>需求: <input type="text" name="demand" /></p>
    <p>内容: <input type="text" name="introduce" /></p>
    <p>成熟度: <input type="number" name="ripe" /></p>
    <p>标签1: <input type="text" name="tag1" /></p>
    <p>标签2: <input type="text" name="tag2" /></p>
    <p>标签3: <input type="text" name="tag3" /></p>
    <input type="submit" value="Summit" />
</form>
    <img src="http://sanchuang.vaiwan.cn/img/projects/default.png">
</body>
</html>
```
