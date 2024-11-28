# 2024/11/28 18:04:55
# 2024/11/28 18:30:55 AC.
dir8 = [[2, 1], [1, 2], [-1, 2], [-2, 1], [-2, -1], [-1, -2], [1, -2], [2, -1]]
if __name__ == "__main__":
    N, M = map(int, input().split())
    A = list()
    B = list()
    for i in range(M):
        a, b = map(int, input().split())
        A.append(a)
        B.append(b)
    st = set()
    for i in range(M):
        st.add((A[i], B[i]))
        for da, db in dir8:
            a = A[i] + da
            b = B[i] + db
            if a < 1 or N < a:
                continue
            if b < 1 or N < b:
                continue
            st.add((a, b))
    # # debug
    # for s in st:
    #     print(s)
    # print("len(st): ", len(st))

    print(N**2 - len(st))

# 取られる座標をすべてsetに詰めれば良い？(2024/11/28 18:06:38)
