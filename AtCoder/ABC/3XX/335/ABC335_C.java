// 2024/02/17 03:37:48
// 2024/02/17 04:56:11 AC.
import java.util.Scanner;
import java.awt.Point;

public class Main{ // ファイル名は Main.拡張子 になるらしい…
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int Q = sc.nextInt();
        Dragon dragon = new Dragon(N);
        for (int i = 0; i < Q; i++) {
            int q = sc.nextInt();
            switch (q) {
                case 1:
                    dragon.move(sc.next());
                    break;
                case 2:
                    Point ans = dragon.get_pos(sc.nextInt());
                    System.out.println(String.format("%d %d", (int)ans.getX(), (int)ans.getY()));
                    break;
            }
        }
        sc.close();
    }
}

class Dragon{
    private int size;
    private Point[] parts;
    private int head;
    Dragon(int n){
        this.size = n;
        this.head = 0;
        this.parts = new Point[n];
        for (int i = 0; i < n; i++) {
            this.parts[i] = new Point(i + 1, 0);
        }
    }
    /**
     * n番目のパーツのd個先の要素のindexを返す
     * @param n 基準となるindex (0 ~ size-1)
     * @param d 差分
     * @return nからd個先のindex
     */
    private int next(int n, int d){
        return (this.size + n - d) % this.size;
    }
    /**
     * n番目のパーツの座標を返す
     * @param n パーツの番号 (1 ~ size)
     * @return n番目のパーツの座標
     */
    Point get_pos(int n){
        return this.parts[this.next(this.head, -(n - 1))];
    }
    /**
     * ドラゴンを指定した向きに1つ移動させる
     * @param C 移動の向き(R:右, L:左, U:上, D:下) 但しy軸は上向き
     */
    void move(String C){
        Point head_pos = new Point(this.parts[this.head]);
        this.head = this.next(this.head, 1);
        switch (C) {
            case "R": head_pos.translate(1, 0); break;
            case "L": head_pos.translate(-1, 0); break;
            case "U": head_pos.translate(0, 1); break;
            case "D": head_pos.translate(0, -1); break;
        }
        this.parts[this.head].setLocation(head_pos);
    }
}

