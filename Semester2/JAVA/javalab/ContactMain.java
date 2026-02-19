import java.util.Scanner;
class ContactMain{
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        System.out.println("enter the number of Contacts");
        int n=sc.nextInt();
        sc.nextLine();
        Personal[] p=new Personal[n];
        for(int i=0;i<n;i++){
            System.out.println("enetr name :");
            String name=sc.nextLine();
            System.out.println("enetr phone no :");
            int phone=sc.nextInt();
            System.out.println("enetr emaiil :");
            String email=sc.nextLine();
            p[i].addContact(name,phone,email);
            System.out.println("enetr type :");
            String type=sc.nextLine();
            System.out.println("enetr dob (dd/mm/yyyy) :");
            String dob=sc.nextLine();
            System.out.println("enetr Relation:");
            String relation=sc.nextLine();
            System.out.println("enetr age :");
            int age=sc.nextInt();
            sc.nextLine();
            System.out.println("enetr gender :");
            String gender=sc.nextLine();
            Personal q = new Personal(type,dob,relation,age,gender);
            p[i]=q;
        }
        System.out.println("contact details");
        for(int i=0;i<n;i++){
           // p[i].Contact.display();
            p[i].displayContact();
    }
    // p.Contact.searchContact(name,p[]);
    // p.filterPersonal()
    }
}