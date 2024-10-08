# Circle 1

## Đề bài

Trong một đồ thị Oxy, cho một hình tròn với tâm là gốc tọa độ (0,0) và bán kính R. Cho 2 điểm bất kỳ trên đường tròn và cho rằng 2 điểm không trùng nhau. Với mỗi K input sẽ cho tọa độ của điểm thứ 3 kết hợp với 2 điểm tạo thành tam giác nội tiếp hình tròn, nếu tam giác đó chứa tâm hình tròn thì trả về "YES", không thì "NO"

Lưu ý, tất cả điểm bài cho đều nằm trên đường tròn, không phải bên trong hay ở ngoài

### Input

- Dòng đầu là R, K (1<= R <= 10^6, 2 <= K <= 10^9)
- 2 dòng kế tiếp là tọa độ hai điểm cho trước trên đường tròn. x y (0 <= x, y <= 10^4)
- K dòng kế tiếp là tọa độ của điểm để kiểm tra: x y (0 <= x, y <= 10^4)

### Output

- K đáp án, "YES" hoặc "NO"
