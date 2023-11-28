import java.util.Scanner;

public class StackArray {
    final int MAX = 10;
    int top = -1, noOfElements = MAX;
    int stack[] = new int[MAX];

    public void push(int value) {
        if (top == noOfElements - 1) {
            System.out.println("\nStack Overflow!...");
        } else {
            top++;
            stack[top] = value;
            System.out.println("\n" + value + " pushed on stack successfully");

            displayStack();
        }
    }

    public void pop() {
        if (top == -1) {
            System.out.println("\nStack Underflow!...");
        } else {
            int removedItem;
            removedItem = stack[top];
            top--;

            System.out.println("\n" + removedItem + " popped from the stack successfully.");
            displayStack();

        }
    }

    public void peek() {
        if (top == -1)
            System.out.println("\nStack is empty!...");
        else {
            System.out.println("\nThe peek of stack is " + stack[top]);
        }
    }

    public void isStackEmpty() {
        if (top == -1)
            System.out.println("\nStack is empty!...");
        else
            System.out.println("\nStack is not empty.");
    }

    public void isStackFull() {
        if (top == noOfElements - 1)
            System.out.println("\nStack is full!...");
        else
            System.out.println("\nStack is not full.");
    }

    public void clearStack() {
        top = -1;
        System.out.println("\nStack cleared successfully!...");
    }

    public void displayStack() {
        if (top != -1) {
            System.out.println("\nThe Stack is,");
            for (int i = top; i > -1; i--) {
                System.out.println(stack[i] + " ");
            }
        } else {
            System.out.println("\nStack is empty!...");
        }
    }

    public static void main(String[] args) {
        StackArray stack = new StackArray();

        int x, choice;
        Scanner input = new Scanner(System.in);

        System.out.println("||=============================================||");
        System.out.println("|| Implementation of Stack using Array in Java ||");
        System.out.println("||=============================================||");

        System.out.println("\n1. Push an element to the stack");
        System.out.println("2. Pop the element from the stack");
        System.out.println("3. Peek element of the stack");
        System.out.println("4. Check whether stack is full or not");
        System.out.println("5. Check whether stack is empty or not");
        System.out.println("6. Empty the whole stack");
        System.out.println("7. Travesing through the stack from the TOP");
        System.out.println("8. Quit");

        while (true) {
            System.out.println("\nEnter your choice: ");
            choice = input.nextInt();

            switch (choice) {
                case 1:
                    System.out.println("\nEnter the element to be pushed onto the stack: ");
                    x = input.nextInt();

                    stack.push(x);
                    break;

                case 2:
                    stack.pop();
                    break;

                case 3:
                    stack.peek();
                    break;

                case 4:
                    stack.isStackFull();
                    break;

                case 5:
                    stack.isStackEmpty();
                    break;

                case 6:
                    stack.clearStack();
                    break;

                case 7:
                    stack.displayStack();
                    break;

                case 8:
                    input.close();
                    System.exit(0);

                default:
                    System.out.println("Invalid Choice!");
                    break;
            }
        }

    }
}
