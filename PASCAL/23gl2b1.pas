var
    n, res, inp: int64;
begin
    readln(n);

    for var i := 1 to n do
    begin
        read(inp);
        if inp > res then
            res := inp;
    end;

    writeln(res);
end.