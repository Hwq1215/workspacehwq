import java.util.Stack;

class TransfromStr{
    public StringBuffer change(StringBuffer nativeStr){
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
            
            if(first(ch)<=first(sign.peek())){
                    back.append(sign.pop());
                    back.append(" ");
                    sign.push(ch);
                }
            else{
                    sign.push(ch);
                }
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

    boolean is_number(char ch){
        if(ch=='0'||ch=='1'||ch=='2'||ch=='3'||ch=='4'||ch=='5'||ch=='6'||ch=='7'||ch=='8'||ch=='9'){
            return true;
        }
        else return false;
    }
    
    boolean is_operate(char ch){
        if(ch=='*'||ch=='/'||ch=='+'||ch=='-'){
            return true;
        }
        else return false;
    } 
    
    int changeBigInt(int local,StringBuffer str){
        char c=str.charAt(local);
        int num=(int)(c-'0');
        int sum=num;
        for(int j=local+1;j!=str.length()-1;j++){
            c = str.charAt(j);
            if(is_number(c)){
            sum = sum*10+num;
            }
            else{
                 break;
            }
        }
        return sum;
}
 
    int first(char operate){
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
public class Calculator{
    public static void main(String [] args) {
        int i=0;
        StringBuffer flow= new StringBuffer("1+(99*8)/5=");
        TransfromStr t=new TransfromStr();
        System.out.println(t.change(flow));
    }
}

