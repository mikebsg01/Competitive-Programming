class arrayReplace {
    public static int[] arrayReplace(int[] inputArray, int elemToReplace, int substitutionElem) {
        for (int i = 0; i < inputArray.length; ++i) {
            int elem = inputArray[i];
            inputArray[i] = elem == elemToReplace ? substitutionElem : elem;
        }

        return inputArray;
    }

    public static void main(String[] args) {
        int[] result = arrayReplace(new int[] {1, 2, 1}, 1, 3);

        for (int i = 0; i < result.length; ++i) {
            if (i > 0) {
                System.out.print(' ');
            }

            System.out.print(result[i]);
        }

        System.out.println();
    }
}