const fi='kxvd2.INP';
      fo='kxvd2.OUT';
var st1,st2:string;a,b:integer;
begin
    assign(input,fi);reset(input);
    assign(output,fo);rewrite(output);
    readln(st1);read(st2); a:=length(st2);
    if st1[1]=st2[a] then write('YES') else write('NO');
end.
