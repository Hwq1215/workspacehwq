import java.util.Scanner;

interface Geometricinterface{
    double perimeter();
    double area();
}

class Triangle implements Geometricinterface{
    public double a;
    public double b;
    public double c;
    public Boolean judge(){
        if(a>b+c||b>a+c||c>a+b){
            return false;
        }
        else return true;
    }
    public double perimeter(){
        return this.a+this.b+this.c;
    }
    public double area(){
    double p=1.0/2*this.perimeter();
        return Math.sqrt(p*(p-a)*(p-b)*(p-c));
    } 
}
class Rectangle implements Geometricinterface{
    public double length;
    public double width;
    public double perimeter(){
        return 2*(length+width);
    }
    public double area(){
        return length*width;
    } 
}

public class app {
    public static void main(String [] args){
        System.out.println("请选择图形\n1.三角形\n2.矩形");
        Scanner scan=new Scanner(System.in);
        if(scan.hasNextInt()){
        int input=scan.nextInt();
            if(input==1){
                int cnt=0;
                Triangle t=new Triangle();
                System.out.println("三角形的三边分别是(用空格分隔)");

                if(scan.hasNextDouble()){
                t.a=scan.nextDouble();
                cnt++;
                }
                if(scan.hasNextDouble()){
                t.b=scan.nextDouble();
                cnt++;
                }
                if(scan.hasNextDouble()){
                cnt++;
                t.c=scan.nextDouble();
                }

                if(cnt==3){
                    if(t.judge()){
                        System.out.println("周长是"+t.perimeter());
                        System.out.println("面积是"+t.area());
                        cnt=0;
                    }
                    else{
                        System.out.println("\n错误，不是三角形的三边");
                    }
                }
                else{
                System.out.println("错误，请用正确格式输入");
                cnt=0;
                }
            }
            else if(input==2){
                int cnt=0;
                Rectangle r=new Rectangle();
                System.out.println("矩形的长宽分别是(用空格分隔)");

                if(scan.hasNextDouble()){
                r.length=scan.nextDouble();
                cnt++;
                }
                if(scan.hasNextDouble()){
                r.width=scan.nextDouble();
                cnt++;
                }
                
                if(cnt==2){
                    System.out.println("周长是"+r.perimeter());
                    System.out.println("面积是"+r.area());
                    cnt=0;
                }
                else{
                System.out.println("错误，请用正确格式输入");
                cnt=0;
                }
            }
            else{
            System.out.println("不是选项");
            }
        }
        else{
            System.out.println("请输入一个整数");
        }
        scan.close();
    }
}
