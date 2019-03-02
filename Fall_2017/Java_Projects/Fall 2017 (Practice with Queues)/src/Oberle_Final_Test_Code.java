//Oberle_Final_Test_Code

import java.util.*;
public class Oberle_Final_Test_Code
{
 public static void main(String[] args)
 {
 Queue<Integer> myQueue = new LinkedList<>();
 myQueue.add(1);
 myQueue.add(2);
 myQueue.add(3);
 myQueue.add(4);
 myQueue.add(5);
 myQueue.add(6);
 myQueue.add(7);

 System.out.println("I have the following in my queue: " + myQueue);
 int deleted_element = myQueue.remove();
 System.out.println("The removed entry is: " + deleted_element);
 System.out.println("The queue after removing the element:");
 System.out.println(myQueue);
 int head = myQueue.peek();
 System.out.println("The element at the head of queue is: " + head);
 int size = myQueue.size();
 System.out.println("The size of the queue is: " + size);
 }
}