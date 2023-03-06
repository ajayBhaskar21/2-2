import java.io.IOException;
import java.util.*;

class ChildThread extends Thread {
    private volatile boolean running = true;
    int num;
    ChildThread(int number){
        num = number;
    }
    public void run() {
        while (running) {
            System.out.println("Thread-" + num + " running");
            try {
                Thread.sleep(1000); // Sleep for 1 second
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        System.out.println("Thread-" + num + " stopped");
    }

    public void stopThread() {
        running = false;
    }
}



public class kill1 {
    
    public static void main(String[] args) throws InterruptedException, IOException{
        Scanner input = new Scanner(System.in);
        ChildThread childThread1 = new ChildThread(1);
        childThread1.start();

        System.out.println("Press enter to stop the thread-1 and start thread-2");
        System.in.read(); // Wait for user input

        childThread1.stopThread(); // Stop the child thread

        childThread1.join(); // Wait for the child thread to finish
        
        
        ChildThread childThread2 = new ChildThread(2);
        childThread2.start();

        System.out.println("Press enter to stop the thread-2 and start thread-3");
        String s;
        s = input.nextLine();
        System.in.read(); // Wait for user input

        childThread2.stopThread(); // Stop the child thread

        childThread2.join(); // Wait for the child thread to finish

        ChildThread childThread3 = new ChildThread(3);
        childThread3.start();

        System.out.println("Press enter to stop the thread-3 and start thread-4");
        s = input.nextLine();
        System.in.read(); // Wait for user input

        childThread3.stopThread(); // Stop the child thread

        childThread3.join(); // Wait for the child thread to finish

        ChildThread childThread4 = new ChildThread(4);
        childThread4.start();



    }
}
