var	f,w,p,l,h:array [0..400] of longint;
	n,mp,i:longint;
begin
	read(n,mp);
	fillchar(f,sizeof(f),0);
	fillchar(w,sizeof(w),0);
	fillchar(p,sizeof(p),0);
	fillchar(l,sizeof(l),0);
	fillchar(h,sizeof(h),0);
	randomize;
	for i:=1 to n do l[i]:=random(10000);
	f[1]:=0;
	for i:=2 to n do begin f[i]:=random(i-2)+1; inc(h[f[i]]); end;
	p[1]:=mp-random(mp div 2);
	w[1]:=mp;
	for i:=2 to n do
	begin
		p[i]:=p[f[i]]-random(p[f[i]]);
		w[i]:=random(mp);
	end;
	assign(output,'lamp.in');
	rewrite(output);
	writeln(n);
	for i:=1 to n do writeln(f[i],' ',w[i],' ',p[i],' ',l[i]);
	close(output);
end.