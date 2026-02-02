import java.util.Scanner;
class CPU{
    double price;
    class Processor{
        int cores;
        String Manufacturer;
    static class RAM{
        int memory;
        String Manufacturer;
    }
}
}
class CPUdrive{
    public static void main(String []args){
        Scanner sc=new Scanner(System.in);
        System.out.println("enter the price of cpu:");
        double p=sc.nextDouble();
        CPU cpu=new CPU();
        cpu.price=p;
        CPU.Processor proc=cpu.new Processor();
        System.out.println("enter number of cores:");
        proc.cores=sc.nextInt();
        System.out.println("enter processor manufacturer:");
        proc.Manufacturer=sc.next();
        CPU.RAM ram=new CPU.RAM();
        System.out.println("enter ram memory:");
        ram.memory=sc.nextInt();
        System.out.println("enter ram manufacturer:");
        ram.Manufacturer=sc.next();
        System.out.println("cpu price is:"+cpu.price);
        System.out.println("processor cores:"+proc.cores);
    }
}