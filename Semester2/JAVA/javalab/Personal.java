public class Personal extends Contact{
    String type;
    String dob;
    String relation;
    int age;
    String gender;
    Personal(String name,int phone,String email,String type,String dob,String relation,int age,String gender){
        super(name,phone,email);
        this.type=type;
        this.dob=dob;
        this.relation=relation;
        this.age=age;
        this.gender=gender;
    }
    void addPersonal(String type,String dob,String relation,int age,String gender){
        this.type=type;
        this.dob=dob;
        this.relation=relation;
        this.age=age;
        this.gender=gender;
    }
    void displayContact(){
        System.out.println("Type :"+type);
        System.out.println("dob :"+age);
        System.out.println("relation:"+relation);
        System.out.println("age :"+age);
        System.out.println("gender :"+gender);
    }
    void filterPersonal(){}
    }