%http://www.mathworks.com/help/fixedpoint/ug/convert-fast-fourier-transform-fft-to-fixed-point.html
%clc;
%start of matlab FFT smaple code
n = 1024;                                     % Number of points
Fs = 4;                                     % Sampling frequency in Hz
t  = (0:(n-1))/Fs;                          % Time vector
f  = linspace(0,Fs,n);                      % Frequency vector
f1 = 2; f2 = 30;                           % Frequencies, in Hz
a1 = 20; a2 = 40;
%x0 = cos(2*pi*f0*t) + 0.55*cos(2*pi*f1*t);  % Time-domain signal
for i=1:n
    x0(i) = a1*cos(f1*2.0*(i-1)*3.1415926535/n)+a2*cos(f2*2.0*(i-1)*3.1415926535/n) + 100;
end
x0 = complex(x0);                           % The textbook algorithm requires the input to be complex

w0 = fidemo.fi_radix2twiddles(n);
y0 = fft(x0); % MATLAB's built-in FFT for comparison
x = sfi(x0);
w = sfi(w0);

y = fi_m_radix2fft_withscaling(x,w);
fidemo.fi_fft_demo_plot(real(x), y, y0/n, n, 'Fixed-point data',{'Fixed-point FFT with scaling','Scaled built-in'});

re = test2(:,1);
im = test2(:,2);
x = 0:1:length(re)-1;

amp = sqrt(re.^2 + im.^2)

plot(x,amp)