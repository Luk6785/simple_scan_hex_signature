1. Chức năng chính:
    - Quét tất cả các file có trong path thư mục mà người dùng nhập vào dựa trên signature bằng mã hex từ đó sẽ quét xem signature có tồn tại trong file hay không rồi in ra box (Không quét file lớn hơn 50MB)
2. Flow của chương trình
    - Người dùng sẽ chọn path của folder cần quét và nhập signature cần tìm bằng mã hex => ấn "Quét".
    - Button "Quét" sẽ nhận event click và làm nhiệm vụ scan directory và đưa lại kết quả cho người dùng.
    => Đa luồng vô cùng quan trọng: Người dùng có thể thao tác với các API khác mà không cần đợi thread trước đó hoàn thành nhiệm vụ. Chia công việc quản lý thuận lợi hơn, giúp giải quyết vấn đề nhanh chóng vượt trội.
3. Cấu trúc file
    - Thread chính main được viết trong MyForm.cpp và cũng được start ở đó
    - Mọi event được chuyển đến file MyForm.h và được xử lý luôn ở đó
    - x64 chứa các file Debug và Release đã build
4. Ưu nhược điểm của đa luồng
    a, Ưu điểm
        - Đa luồng giúp chia công việc chạy song song nhau, cùng nhau làm việc mà không cần phải đợi công việc trước đó thực hiện xong.
        - Mỗi luồng có thể sử dụng chung tài nguyên hoặc độc lập với nhau giúp tiết kiệm thời gian hoàn thành chương trình.

    b, Nhược điểm
        - Khi xử lý nhiều luồng nếu lập trình viên mà không kiểm soát tốt các luồng của mình dẫn đến tranh chấp bộ nhớ, deadlock, thậm chí crash chương trình nếu tạo quá nhiều thread.
    c, Cơ chế chống xung đột trong project_5
        - Vì các event <textBox->Text, MessengerBox::Show,..> đều chạy trên Thread Main của chương trình nên em sử dụng Control::CheckForIllegalCrossThreadCalls = false;  
        => Control::CheckForIllegalCrossThreadCalls = false; giúp các thread khác có thể sử dụng chung tài nguyên với main thread và giúp các thread không bị xung đột lẫn nhau.
        - Và khi tắt chương trình thread không mất đi và nó vẫn thực hiện nhiệm vụ xong rồi mới mất nên em dùng Thread->IsBackground = FALSE; giúp thread có thể tự kết thúc khi chương trình tự động ngắt đột ngột.

