import java.util.Scanner;

class ArrayOperationsDS {
    static final int MAX = 100;
    ArrayOperationsDS next;
    float arr[] = new float[MAX];
    float x;
    int noOfElements, choice, position;
    Scanner input = new Scanner(System.in);

    public void displayArrayAndLength() {
        System.out.print("\nThe Array elements are: ");
        for (int i = 0; i < noOfElements; i++)
            System.out.print(arr[i] + " ");
        System.out.println("\nThe length of the array is " + noOfElements);
        System.out.println();
    }

    public void insertAtFirstPosition() {
        System.out.println("\nEnter the element to be inserted at first position: ");
        x = input.nextInt();

        // shifting all the elements to one position on the right
        for (int i = noOfElements - 1; i >= 0; i--) {
            arr[i + 1] = arr[i];
        }
        // inserting at first position and incrementing the noOfElements by 1
        arr[0] = x;
        noOfElements++;

        displayArrayAndLength();
    }

    public void insertAtLastPosition() {
        System.out.println("\nEnter the element to be inserted at last position: ");
        x = input.nextInt();

        // inserting at last position and incrementing the noOfElements by 1
        arr[noOfElements] = x;
        noOfElements++;

        displayArrayAndLength();
    }

    public void insertAtGivenPosition() {
        System.out.println("\nEnter the element to be inserted: ");
        x = input.nextInt();

        System.out.println("Enter the position where you wanna insert: ");
        position = input.nextInt();

        for (int i = noOfElements - 1; i >= position - 1; i--)
            arr[i + 1] = arr[i];

        arr[position - 1] = x;
        noOfElements++;

        displayArrayAndLength();
    }

    public void searchElement() {
        System.out.println("Enter the element to be searched: ");
        x = input.nextInt();

        for (int i = 0; i < noOfElements; i++) {
            if (arr[i] == x) {
                System.out.println("\n" + x + " found at position " + (i + 1));
                return;
            }
        }

        // If the value is not found
        System.out.println("\n" + x + " not found.");
    }

    public void removeElement() {
        boolean isElementFound = false;
        int i;

        System.out.println("\nEnter the element to be removed: ");
        x = input.nextInt();

        System.out.println("Enter the position of the element: ");
        position = input.nextInt();

        x = arr[position - 1];
        for (i = 0; i < noOfElements; i++) {
            if (arr[i] == x) {
                isElementFound = true;
                break;
            }
        }

        if (!isElementFound)
            System.out.println("Element not found!...");
        else {
            for (int j = i; j < noOfElements - 1; j++) {
                arr[j] = arr[j + 1];
            }
            noOfElements--;
        }

        displayArrayAndLength();
    }

    public void replaceElement() {
        boolean isElementFound = false;
        int i;

        System.out.println("Enter the position of the element: ");
        position = input.nextInt();

        x = arr[position - 1];
        for (i = 0; i < noOfElements; i++) {
            if (arr[i] == x) {
                isElementFound = true;
                break;
            }
        }

        if (!isElementFound)
            System.out.println("Element not found!...");
        else {
            System.out.println("\nEnter the new element: ");
            x = input.nextInt();

            arr[i] = x;
        }

        displayArrayAndLength();
    }

    public void isArrayEmpty() {
        if (noOfElements != 0)
            System.out.println("The array is not empty");
        else
            System.out.println("The array is empty");
    }

    public static void main(String[] args) {
        ArrayOperationsDS arrayOperationsDS = new ArrayOperationsDS();

        System.out.println("Enter the size of the array: ");
        arrayOperationsDS.noOfElements = arrayOperationsDS.input.nextInt();

        if (arrayOperationsDS.noOfElements > MAX) {
            System.out.println("Array exceeds maximum size...");
            return;
        }

        System.out.println("\nEnter " + arrayOperationsDS.noOfElements + " elements");
        for (int i = 0; i < arrayOperationsDS.noOfElements; i++)
            arrayOperationsDS.arr[i] = arrayOperationsDS.input.nextInt();

        System.out.print("\nThe Array elements are: ");
        for (int i = 0; i < arrayOperationsDS.noOfElements; i++)
            System.out.print(arrayOperationsDS.arr[i] + " ");
        System.out.println();

        System.out.println("\n1. Insert at first position & display length");
        System.out.println("2. Insert at last position & display length");
        System.out.println("3. Insert at a given position & display length");
        System.out.println("4. Remove an element & display length");
        System.out.println("5. Replace an element & display length");
        System.out.println("6. Search an element & display position");
        System.out.println("7. Check if the list is empty");
        System.out.println("8. Quit");

        while (true) {
            System.out.println("\nEnter your choice: ");
            arrayOperationsDS.choice = arrayOperationsDS.input.nextInt();

            switch (arrayOperationsDS.choice) {
                case 1:
                    arrayOperationsDS.insertAtFirstPosition();
                    break;

                case 2:
                    arrayOperationsDS.insertAtLastPosition();
                    break;

                case 3:
                    arrayOperationsDS.insertAtGivenPosition();
                    break;

                case 4:
                    arrayOperationsDS.removeElement();
                    break;

                case 5:
                    arrayOperationsDS.replaceElement();
                    break;

                case 6:
                    arrayOperationsDS.searchElement();
                    break;

                case 7:
                    arrayOperationsDS.isArrayEmpty();
                    break;

                case 8:
                    System.exit(0);
                    break;

                default:
                    System.out.println("Invalid choice!!!");
                    break;
            }
        }
    }
}