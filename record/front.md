# 前端
* 和之前那一样是Code, Msg, Data 封装的json数据
## 登录
* 接口：
```java
    @GetMapping("/login/in")
```
* 传到后端的数据：
```javascript
    FormData{
        userId: int
        password : string
    }
```
* 传回前端的数据：
```javascript
    code{}
    msg{}
    data{null}
```
|状态|code|
|----|----|
|用户存在|200|
|密码错误|210|
|用户不存在|220|
</br><b>

## 使用说明
* 接口：
```java
    @GetMapping("/instruction")
```
* 传到前端的数据：
```javascript
    data{
       imgPath: string //是一个图片名字，和之前一样,你需要在前端拼接 http://localhost:8081/
    }
```
</br><b>

## 个人信息修改
1. 获取用户信息的接口：
```java
    @GetMapping("user/get")
    //带上userId
```
* 传到前端的数据：
```javascript
    data{
        userId: int
        password : string
    }
```
1. 修改用户信息的接口：
```java
    @PostMapping("user/change")
```
* 传到后端的数据：
```javascript
    FormData{
        userId: int
        password : string
    }
```
*传回前端的返回值：
状态|code|
|----|----|
|修改成功|200|
|用户不存在|210|
|修改失败|404|
</br><b>

## 密文分类记录
```java
    
```
</br><b>

## 抓包
* 不做

</br><b>

## 在线加密
* 暂时不做