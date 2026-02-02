// Create CPU with attribute price. Create inner class Processor(no. of cores, manufacturer) and static nested class RAM(memory, manufacturer).Create an object of CPU and print information of processor and RAM 
import java.util.Scanner;
class CPU {
    double price;
    CPU(double p) {
        price = p;
    }
    class Processor {
        int cores;
        String manufacturer;
        Processor(int c, String m) {
            cores = c;
            manufacturer = m;
        }
        void displayInfo() {
            System.out.println("Processor Cores: " + cores);
            System.out.println("Processor Manufacturer: " + manufacturer);
        }
    }
    static class RAM {
        int memory;
        String manufacturer;
        RAM(int m, String man) {
            memory = m;
            manufacturer = man;
        }
        void displayInfo() {
            System.out.println("RAM Memory: " + memory);
            System.out.println("RAM Manufacturer: " + manufacturer);
        }
    }
}
class cpudrive {
    public static void main(String []args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter CPU Price: ");
        double price = sc.nextDouble();
        CPU cpu = new CPU(price);
        System.out.print("Enter Processor Cores: ");
        int cores = sc.nextInt();
        System.out.print("Enter Processor Manufacturer: ");
        String procManu = sc.next();
        CPU.Processor processor = cpu.new Processor(cores, procManu);
        System.out.print("Enter RAM Memory (in GB): ");
        int memory = sc.nextInt();
        System.out.print("Enter RAM Manufacturer: ");
        String ramManu = sc.next();
        CPU.RAM ram = new CPU.RAM(memory, ramManu);
        System.out.println("\nCPU Information:");
        System.out.println("CPU Price: " + cpu.price);
        processor.displayInfo();
        ram.displayInfo();
        sc.close();
    }
}