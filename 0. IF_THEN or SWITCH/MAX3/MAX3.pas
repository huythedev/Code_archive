const
    fi = 'MAX3.INP';
    fo = 'MAX3.OUT';
var
    a,b,c,max:longint;
procedure docfile;
    begin
        assign(input,fi); reset(input);
        assign(output,fo); rewrite(output);
        readln(a,b,c);
    end;
procedure xuly;
    begin
        max:=a;
        If max<b then max:=b;
        If max<c then max:=c;
        write(max);
    end;
begin
    docfile;
    xuly;
end.