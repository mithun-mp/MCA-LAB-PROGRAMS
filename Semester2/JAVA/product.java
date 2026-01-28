import java.util.Scanner;
class product{
    int pcode;
    String pname;
    double price;
    void getData(Scanner sc){
        System.out.print("enter product code :");
        pcode=sc.nextInt();
        System.out.print("enter product name :");
        pname=sc.next();
        System.out.print("enter product price:");
        price=sc.nextDouble();
    }
    void display(){
        System.out.println("product code : "+pcode);
        System.out.println("product name : "+pname);
        System.out.println("product price: "+price);
    
    }
}
class productdrive{
    public static void main(String []args){
        Scanner sc=new Scanner(System.in);
        product p1=new product();
        product p2=new product();
        product p3=new product();
        System.out.println("enter details of product :");
        p1.getData(sc);
        p2.getData(sc);
        p3.getData(sc);
        product lowest=p1;
        if (p2.price <lowest.price){
            lowest=p2;
        }
        if(p3.price<lowest.price){
            lowest=p3;
        }
        System.out.println("the lowest price product is :");
        lowest.display();
        sc.close();
    }
}