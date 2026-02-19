public class Contact{
    String name;
    int phone;
    String email;
    Contact(String name,int phone,String email){
        this.name=name;
        this.phone=phone;
        this.email=email;
    }
    void addContact(){
        this.name=name;
        this.phone=phone;
        this.email=email;
    }
    // void searchContact(String name,Personal [] p){
    //     for(contacts:p){
    //         if(name.compareToIgnoreCase(contacts.Contact.name)==0){
    //             System.out.println("contact found");
    //             System.out.println("Name:"+contacts.Contact.name);
    //             System.out.println("Phone :"+contacts.Contact.phone);
    //         }
    //     }
    // }
    void display(){
        System.out.println("name  :"+name);
        System.out.println("Phone :"+phone);
        System.out.println("Email :"+email);
    }
}