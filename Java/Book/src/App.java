/*设计一个程序，表达各种读物、如小说Novels、杂志Magazine、期刊Joural、课本TextBook等，每种读物有相同的属性，如页数、价格等，
也有不同的属性，如杂志和期刊都有出版周期，而课本有适合对象（读者）。
写一个测试类的main()来产生一些列随机的读物，并输出它们的信息。（不需要使用Scanner输入，直接在代码中对各属性进行赋值）
说明：首先填好学号、姓名、邮箱等信息，然后在程序文本框中编写程序，编写完成后点击右边的“运行程序”按钮，
在下面我的作业区域就会显示运行结果及要提交的程序代码，如果程序没有问题，点击下面的提交按钮，如果程序执行错误，可以修改程序重新运行。
*/

class Books{
    private int pages;
    private double prices;
    public void set_pages(int p){
        this.pages=p;
    }
    public void set_prices(double pr){
        this.prices=pr;
    }
    public int get_pages(){
        return this.pages;
    }
    public double get_prices(){
        return this.prices;
    }
}

class Novels extends Books{}
class Magazine extends Books{
    private String data;
    public void set_data(String input){
        this.data=input;
    }
    public String get_data(){
        return this.data;
    }
}
class Joural extends Books{
    private String data;
    public void set_data(String input){
        this.data=input;
    }
    public String get_data(){
        return this.data;
    }
}
class TextBook extends Books{
    private String data;
    private String reader;
    public void set_data(String input){
        this.data=input;
    }
    public String get_data(){
        return this.data;
    }
    public void set_reader(String input){
        this.reader=input;
    }
    public String get_reader(){
        return this.reader;
    }
}
public class App {
    public static void main(String[] args){
        TextBook B=new TextBook();
        B.set_pages(12);
        B.set_prices(6.8);
        B.set_data("2002.6.5");
        B.set_reader("kids");
        System.out.println("pages:"+B.get_pages()+"\nprices:"+B.get_prices()+"\ndata:"+B.get_data()+"\nreader:"+B.get_reader());
    }
}
