function x = fi_m_radix2fft_withscaling(x, w)
n = length(x);  t = log2(n);
x = fidemo.fi_bitreverse(x,n);
% Generate index variables as integer constants so they are not computed in
% the loop.
LL = int32(2.^(1:t)); rr = int32(n./LL); LL2 = int32(LL./2);
for q=1:t
    L = LL(q); r = rr(q); L2 = LL2(q);
    for k=0:(r-1)
        for j=0:(L2-1)
            temp          = w(L2-1+j+1) * x(k*L+j+L2+1);
            x(k*L+j+L2+1) = bitsra(x(k*L+j+1) - temp, 1);
            x(k*L+j+1)    = bitsra(x(k*L+j+1) + temp, 1);
        end
    end
end