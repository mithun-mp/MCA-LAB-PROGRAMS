import java.util.Scanner;
class Estring{
    String Estring(String s){
        this.str=s;
        return str;
    }
    String str;
    String reverse_string(String s){
        String str=s;
        String reversed="";
        for(int i=str.length()-1;i>=0;i--){
            reversed+=str.charAt(i);
        }
        System.out.println("Reversed String: " + reversed);
        return reversed;
    }
    String reverse_each_word(String s){
        String str=s;
        String[] words=str.split(" ");
        String result="";
        for(String word:words){
            String reversed_word="";
            for(int i=word.length()-1;i>=0;i--){
                reversed_word+=word.charAt(i);
            }
            result+=reversed_word+" ";
        }
        System.out.println("Reversed Each Word: " + result.trim());
        return result.trim();
    }
    String count_characters(String s){
        String str=s;
        int count=0;
        for(int i=0;i<str.length();i++){
            if(Character.isLetter(str.charAt(i))){
                count++;
            }
        }
        System.out.println("Character Count (excluding spaces): " + count);
        return Integer.toString(count);
    }
    String title_case(String s){
        String str=s;
        String[] words=str.split(" ");
        String title_case="";
        for(String word:words){
            if(word.length()>0){
                title_case+=Character.toUpperCase(word.charAt(0));
                title_case+=word.substring(1).toLowerCase()+" ";
            }
        }
        System.out.println("Title Case: " + title_case.trim());
        return title_case.trim();
    }
}
class Estringdrive{
    public static void main(String []args){
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter a string:");
        String input=sc.nextLine();
        estring es=new estring(input);
        es.reverse_string(input);
        es.reverse_each_word(input);
        es.count_characters(input);
        es.title_case(input);
        sc.close();
    }
}