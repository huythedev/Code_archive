const
    fi = 'MAX2.INP';
    fo = 'MAX2.OUT';
var
    a,b:longint;
procedure docfile;
    begin
        assign(input,fi); reset(input);
        assign(output,fo); rewrite(output);
        readln(a,b);
    end;
procedure xuly;
    begin
        If a>b then write(a) else write(b);
    end;
begin
    docfile;
    xuly;
end.