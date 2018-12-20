uses
  sortread;

var
  i,x: integer;
  ok: boolean;
begin 
  repeat
    ok:=true;
    for i:=1 to s.Count-1 do 
      if s.Src[i]>s.Src[i+1] then begin 
        x:=s.Src[i];  s.Src[i]:=s.Src[i+1];  s.Src[i+1]:=x;
        ok:=false;
      end;
  until ok;

  assign(output,'4.out');
  rewrite(output);
  for i:=1 to s.Count do writeln(s.Src[i]);
  close(output);
end.