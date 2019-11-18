class evenDigitsOnly {
    public static boolean evenDigitsOnly(int n) {
        int d;

        while (n > 0) {
            d = n % 10;

            if (d % 2 != 0) {
                return false;
            }

            n /= 10;
        }

        return true;
    }

    public static void main(String[] args) {
        System.out.println(evenDigitsOnly(248622));
        System.out.println(evenDigitsOnly(642386));
    }
}