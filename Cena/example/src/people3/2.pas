var
  a,b: int64;

function Mult(a,b: int64): string;
var
  i: integer;
  Res: string;
begin 
  a:=a*b;
  Str(a,Res);
  i:=Length(Res);
  while i>3 do begin 
    dec(i,3);
    Res:=copy(Res,1,i)+','+copy(Res,i+1,length(Res)-i);
  end;
  Mult:=Res;
end;

begin 
  assign(input,'2.in');
  reset(input);
  readln(a);
  readln(b);
  close(input);
 
  assign(output,'2.out');
  rewrite(output);
  writeln(Mult(a,b));
  close(output);
end.