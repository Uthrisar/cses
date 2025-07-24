def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    T = int(data[0])
    index = 1;
    for _ in range(T):
        N = int(data[index])
        index += 1
        A = list(map(int, data[index: index+N]))
        index += N
        P = [0]*(N+1)
        for i in range(1, N+1):
            P[i] = P[i-1]^A[i-1]
        S = set()
        for i in range(1, N+1):
            S.add(A[i-1]&P[i-1])
        S.add(0)

        mx_score = 0;
        for x0 in S:
            X = x0
            score = 0
            for i in range(1, N+1):
                if X == A[i]:
                    score += X
                else:
                    X ^= A[i]
            mx_score = max(mx_score, score)

