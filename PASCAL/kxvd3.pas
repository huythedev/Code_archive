const fi='kxvd3.INP';
      fo='kxvd3.OUT';
var st1,st2:string;a,b:integer;
begin
    assign(input,fi);reset(input);
    assign(output,fo);rewrite(output);
    readln(st1);
    a:=length(st1);
    for b:=a downto 1 do write(st1[b]);
end.
