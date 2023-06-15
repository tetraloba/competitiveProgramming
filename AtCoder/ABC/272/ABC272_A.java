// 2023/06/15 22:37:06
// 2023/06/15 23:03:46 AC.
import java.util.Arrays;
import java.util.Scanner;

public class Main{ // ファイル名は Main.拡張子 になるらしい…
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[] al = new int[N];
        for (int i = 0; i < N; i++) {
            al[i] = sc.nextInt();
        }
        sc.close();
        System.out.println(Arrays.stream(al).sum());
    }
}