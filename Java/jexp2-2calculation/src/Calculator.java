import java.util.Stack;
import java.util.Scanner;
import java.util.regex.*;
//将中序表达式转化为后序表达式
class TransfromStr extends BaseMethod{
    public StringBuffer change(String nativeStr){
    Stack<Character> sign=new Stack<>();
    char ch;
    StringBuffer back=new StringBuffer();
    for(int i = 0;i<nativeStr.length();i++){
        ch=nativeStr.charAt(i);
        
        if((sign.empty()&&is_operate(ch))||ch=='('){
            sign.push(ch);
        }
        else if(is_number(ch)){
            back.append(Integer.toString(changeBigInt(i,nativeStr)));
            i+=(Integer.toString(changeBigInt(i,nativeStr))).length()-1;
            back.append(" ");
        }
                
        else if(ch==')'){
                while(sign.peek()!='('){
                    back.append(sign.pop());
                    back.append(" ");
                }
                sign.pop();
        }
        else if(is_operate(ch)){

                while(!sign.empty()&&first(ch)<=first(sign.peek())){
                    back.append(sign.pop());
                    back.append(" ");
                }
                    sign.push(ch);
                
            if(is_number(nativeStr.charAt(i+1))){
                    back.append(Integer.toString(changeBigInt(i+1,nativeStr)));
                    back.append(" ");
                    i+=(Integer.toString(changeBigInt(i+1,nativeStr))).length();
                    }

        }                                                           
       else if(ch=='='){
           while(!sign.empty()){
               back.append(sign.pop());
               back.append(" ");
           }
       }
    }
    return back;
}
    //该函数只需类内部调用,运用封装
    private static int changeBigInt(int local,String str){
        char c=str.charAt(local);
        int num=(int)(c-'0');
        int sum=num;
        for(int j=local+1;j!=str.length()-1;j++){
            c = str.charAt(j);
            if(is_number(c)){
            num=(int)(c-'0');
            sum = sum*10+num;
            }
            else{
                 break;
            }
        }
        return sum;
}
 
    static int first(char operate){
        if(operate=='*'||operate=='/'){
            return 2;
        }
        else if(operate=='+'||operate=='-'){
            return 1;
        }
        else{
            return 0;
        }
    }

}
//根据后序表达式进行计算
class GetResult extends BaseMethod{
    static int resultIs(StringBuffer input){
        Stack<Integer> num_stack=new Stack<Integer>();
        for(int i=0;i<input.length();i++){
            char ch=input.charAt(i);
            if(is_operate(ch)){
                int num_b=num_stack.pop();
                int num_a=num_stack.pop();
                int res=judge(ch,num_a,num_b);
                num_stack.push(res);
                if(input.length()-1!=i) i++;
            }
            else if(is_number(ch)){
                num_stack.push(changeToInt(i, input));
                i+=num_jump(i,input);
                }
            else{

            }
            }
        
        return num_stack.pop();
     }
    
    private static int changeToInt(int local,StringBuffer into){
        int num = (int)(into.charAt(local)-'0');
        int sum = num;
        for(int i = local+1;into.charAt(i)!=' '&&is_number(into.charAt(i));i++){
            num = (int)(into.charAt(i)-'0');
            sum = sum*10+num;
        }
        return sum;
    }   
    private static int num_jump(int local,StringBuffer into){
        int cnt=0;
        for(int i = local;into.charAt(i)!=' '&&is_number(into.charAt(i));i++){
            cnt++;
        }
        return cnt;
    }
}
//一些可以继承的基本方法
class BaseMethod{
    static boolean is_number(char ch){
        if(ch=='0'||ch=='1'||ch=='2'||ch=='3'||ch=='4'||ch=='5'||ch=='6'||ch=='7'||ch=='8'||ch=='9'){
            return true;
        }
        else return false;
    }
    
    static boolean is_operate(char ch){
        if(ch=='*'||ch=='/'||ch=='+'||ch=='-'){
            return true;
        }
        else return false;
    } 
    static int judge(char ch,int num_a,int num_b) {
        switch(ch){
            case '+':
                return num_a+num_b;
            case '-':
                return num_a-num_b;
            case '*':
                return num_a*num_b;
            case '/':
                return num_a/num_b;
            default:
                return 0;
        }
    }
}

public class Calculator{
    public static void main(String [] args) {
        String flow= new String();
        Scanner scan=new Scanner(System.in);
        System.out.println("请输入表达式，以等号(=)结尾");
        String pattern ="^[\\d\\+\\*/\\-\\)\\(]+=$";
       
        if(scan.hasNext()){

            flow=scan.next();
        boolean flag=Pattern.matches(pattern,flow);

        if(flag){
        TransfromStr t=new TransfromStr();
        System.out.println("逆波兰式是: "+t.change(flow));
        System.out.println("计算结果是: "+GetResult.resultIs(t.change(flow)));
        }
        else{
            System.out.println("输入的式子不合乎规范");
        }
        }
        scan.close();       
    }
}

