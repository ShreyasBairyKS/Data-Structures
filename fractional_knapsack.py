n, W = map(int, input().split())

items = []
for _ in range(n):
    w, p = map(float, input().split())
    items.append((p/w, w, p))

items.sort(reverse=True)

total_profit = 0.0
for ratio, w, p in items:
    if W <= 0:
        break
    if w <= W:
        total_profit += p
        W -= w
    else:
        total_profit += ratio * W
        W = 0

print(f"{total_profit:.2f}")
