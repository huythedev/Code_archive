var 
    n, i, minnum, vitri: int64;
    M: array of int64;
begin
    write('Nhap N: '); readln(n);
    setlength(M, n - 1);
    for i := 0 to n - 1 do
    begin
        write('M[', i + 1, '] = '); readln(M[i]);
    end;
    minnum := M[0];
    for i := 1 to n - 1 do
    begin
        if M[i] < minnum then 
        begin
            minnum := M[i];
            vitri := i;
        end;
    end;
    writeln('Phan tu nho nhat la phan tu thu ', vitri + 1);
end.