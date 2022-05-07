# 一些修改
## 属性标签tag、amount增加，tag为了好建数据库，有三个tag，post提交项时tag可以不用全部都要提交，没有提交的tag我会用字符串 "default" 代替
```java
    public class DealingProject {
        private Integer id;         //项目编号
        private Integer lowPrice,highPrice; //价格
        private Integer amount;     //处理量
        private String port;        //端口
        private String type;        //种类
        private String name;        //项目的名字
        private String demand;      //需求
        private String introduce;   //项目的内容
        private String location;    //项目的地域
        private String ripe;        //成熟度
        private String time ;       //项目开始时间
        private String tag1;         //标签1
        private String tag2;         //标签2
        private String tag3;         //标志3
    }
```