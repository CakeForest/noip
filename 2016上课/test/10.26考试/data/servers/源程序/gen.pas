program genser;

const

   xrseed : cardinal = 100;
   yrseed : cardinal = 1000;


function myrand:cardinal;
begin
	xrseed := 18000*(xrseed and 65535) + 69069 + (xrseed shr 16);
	yrseed := 30903*(yrseed and 65535) + 40692 + (yrseed shr 16);
	myrand := ((xrseed <<16) + (yrseed and 65535));
end;

function random(x:cardinal):cardinal;
begin
  random := myrand mod x;
end;

function random_rank:cardinal;
begin
  random_rank := round(10 - ln(1+random(round(exp(9)))));
end;

procedure generate1;
const
  ts : array[2..7,1..6] of longint = (
     (20,4,20,444,0,20),
     (100,6,10,23427,0,20),
     (1000,3,25,2326,0,1),
     (5000,8,1000,43345,5000*4-5,2),
     (10000,4,5000,2222,20000,1000),
     (30000,10,400,643647, 30000*10 div 2 - 50,1000)
     );
  CN = 1;
  CM = 5;
  CMDEG = 2;
  CRANDS = 4;
  CIMAXR = 3;
  CDT = 6;
  MAXN = 100000;

var
  n, m ,mdeg: longint;
  i, j, a,b,x,mx : longint;
  deg:array[1..MAXN] of longint;
  f : text;
  conn : array[1..MAXN,1..10] of longint;
  connn : array[1..MAXN] of longint;
  tt : longint;
  st : string;

function connect(a,b:longint):boolean;
var
  j : longint;
begin
  for j := 1 to connn[a] do
    if conn[a,j] = b then
    begin
      connect := false;
      exit;
    end;
  inc(connn[a]);
  conn[a,connn[a]] := b;
  connect := true;
end;

begin
  for tt := 2 to 7 do
  begin
    fillchar(connn,sizeof(connn),0);
    fillchar(deg,sizeof(deg),0);
    str(tt,st);
    assign(f,'e'+st+'.in');
    rewrite(f);

    xrseed := ts[tt,CRANDS];
    yrseed := ts[tt,CRANDS];
    n := ts[tt,CN];
    mdeg := ts[tt,CMDEG];
    if ts[tt,CM] = 0 then
      m := n*mdeg div 2
    else
      m := ts[tt,CM];

    mx := 1;
    writeln(f,n,' ',m);
    for i := 1 to n do
    begin
      if tt>0 then
      begin
        x := random_rank;
      end
      else
      begin
        if random(ts[tt,CIMAXR]) = 0 then
          x := 10
        else
         x := random(9) + 1;
      end;
      writeln(f,x);
    end;
    for j := 1 to m do
    begin
{      if j> m - 100 then write(j,' ');}
      
      repeat
        a := random(n)+1;
        b := random(n)+1;
      until (deg[a] < mdeg) and (deg[b] < mdeg) and (a<>b) and (connect(a,b));
      connect(b,a);
      writeln(f,a,' ',b,' ', random(ts[tt,CDT])+1);
      inc(deg[b]);
      inc(deg[a]);
    end;
    close(f);
  end;


    assign(f,'e8.in');
    rewrite(f);

    xrseed := 21420;
    n := 30000;

    for i := 1 to n do
      connn[i] := 1;
    x := 1;
    for j := 1 to 9 do
    begin
      for i := 1 to n do
      begin
        if connn[i] = j then
        begin
          if random(j+1)=0 then
          begin
            inc(connn[i]);
            x := j+1;
          end;
        end;
      end;
    end;
    writeln(f,n,' ',n-1);

    for i := 1 to n do
      writeln(f,connn[i]);

    for j := 1 to n-1 do
    begin
      writeln(f,j,' ',j+1,' ', random(100)+1);
    end;
    close(f);

end;

procedure generate2;
const
  maxn = 15000;
  ts : array[9..10,1..4] of longint  = 
    ((15000,1000,100,12333),
     (5000,100,1,32545));
  CRANDS = 4;
  CN = 1;
  CDT = 3;
  CIMAXR = 2;
var
  s : array[1..2*maxn] of longint;
  f : text;
  n, i, x, y, tt : longint;
  st : string;


begin
  for tt := 9 to 10 do
  begin
    str(tt,st);
    assign(f,'e' +st+ '.in');
    rewrite(f);
    n := ts[tt,CN];
    xrseed := ts[tt,CRANDS];
    yrseed := ts[tt,CRANDS];
    writeln(f,2*n-1,' ',2*n-2);
    for i := 1 to 2*n-1 do
    begin
{      if random(ts[tt,2])=0 then
        writeln(f,10)
      else
        writeln(f,random(9)+1);}
      writeln(f, random_rank);
      s[i] := 0;
    end;
    for i := 1 to n do
      s[i] := 1;

    for i := n+1 to 2*n-1 do
    begin
      repeat
        x := random(2*n-1)+1;
      until s[x] = 1;
      s[x] := 2;
      repeat
        y := random(2*n-1)+1;
      until s[y] = 1;
      s[y] := 2;
      s[i] := 1;
      writeln(f,x,' ',i,' ',random(ts[tt,CDT])+1);
      writeln(f,y,' ',i,' ',random(ts[tt,CDT])+1);
//      write(i,' ');
    end;
    close(f);

  end;
end;

begin
  generate1;
  generate2;
end.

