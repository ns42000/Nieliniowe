  drukarka3d = serial('/dev/ttyUSB0', 'BaudRate', 115200)

fopen(drukarka3d)
%%
nastawa = 0;
radius = 400;
staraa = 0;
starab = round(radius*sin(0-(2*pi/3)));
starac = round(radius*sin(0-(4*pi/3)));

for t = [0:0.05:101]
a = round(radius*sin(t));
b = round(radius*sin(t-(2*pi/3)));
c = round(radius*sin(t-(4*pi/3)));
fprintf(drukarka3d, 'a %i b %i c %i\n %f', [a-staraa, b-starab, c-starac, nastawa])
    while drukarka3d.BytesAvailable == 0
        ;
    end
    while drukarka3d.BytesAvailable > 0
        fscanf(drukarka3d)
    end
staraa = a;
starab = b;
starac = c;
%     fprintf(drukarka3d, "a 5000 b 5000 c 5000")
%     while drukarka3d.BytesAvailable == 0
%         ;
%     end
%     while drukarka3d.BytesAvailable > 0
%         fscanf(drukarka3d)
%     end
end