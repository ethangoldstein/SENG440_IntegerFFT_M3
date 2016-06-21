%http://www.mathworks.com/help/fixedpoint/ug/convert-fast-fourier-transform-fft-to-fixed-point.html
%clc;
clf;

%start of matlab FFT sample code
n = 1024;                                     % Number of points
Fs = 4;                                     % Sampling frequency in Hz
t  = (0:(n-1))/Fs;                          % Time vector
f  = linspace(0,Fs,n);                      % Frequency vector
f1 = 2; f2 = 30;                           % Frequencies, in Hz
a1 = 1000; a2 = 40;
%x0 = cos(2*pi*f0*t) + 0.55*cos(2*pi*f1*t);  % Time-domain signal
for i=1:n
    x0(i) = a1*cos(f1*2.0*(i-1)*3.1415926535/n) + 1000;
end
x0 = complex(x0);                           % The textbook algorithm requires the input to be complex
w0 = fidemo.fi_radix2twiddles(n);
x = sfi(x0);
w = sfi(w0);
y = fi_m_radix2fft_withscaling(x,w); %contains the Ideal Integer FFT

%Calculating Micro FFT based on imported Data
re = Micro_FFT(:,1);
im = Micro_FFT(:,2);
amp = sqrt(re.^2 + im.^2);

%Plotting all the Data
samp = 0:1:length(x)-1;

subplot(4,1,1)
plot(samp,real(x));
title('Input Freqeuncy Time Domain')

subplot(4,1,2) 
plot(samp,abs(y));
title('Matlab IntFFT');

subplot(4,1,3);
plot(samp,amp);
title('Micro IntFFT');

subplot(4,1,4);
plot(samp,abs(y) - transpose(amp));
title('The Difference');


