---
title: "qGaussian: An R package that deal with the Tsallis statistics"

authors:
   - name: Wagner Santos de Lima
     orcid: 0000-0001-8661-4828
     affiliation: Universidade Federal de Sergipe
   - name: Emerson Luis de Santa Helena
     orcid: 0000-0002-9970-3544
     affiliation: Universidade Federal de Sergipe
     
date: 04 April 2017
  
bibliography: paper.bib
---

# Summary

Entropy is a fundamental concept in physics since it is in essence of second law of thermodynamics. 
In the article 'Possible generalization of Boltzmann-Gibbs statistics' [@T88], was 
postulated the Tsallis entropy $S_q[p(x)]=(1-\int_{-\infty}^{\infty}p^q(x)dx)/(q-1)$.
Within the nonextensive approach, the sum of the entropy of two independent subsystems is given by: 
$S_q(a+b)=S_q(a)+S_q(b)+(1-q)S_q(a)S_q(b)$, where $q$ is an entropic index.
The $q$-Gaussian density function $p(x)$ arises from maximizing the $q$-entropy functional $S_q[p(x)]$ under constraints 
[@tsallis] and [@H14] and it is important at the framework of the nonextensive statistical mechanics.

There is a broad literature where the nonextensive approach is used to model systems and/or explain many-body problems and 
issues related to Chaos Theory. In some cases, there exist strong evidences that theory works, certified by a broad 
numerical decade from experimental measurements or numericals simulation that let us obtain a $q$ value by an almost 
flawless curve fitting. In other cases, a lot of observational data are only suggestive of a nonextensive approach. 
A myriad of examples can be found in [@GT04] and [@tsallis]. 

The $q$-Gaussian probability density function, named here $q$PDF [@santahelena], with $q$-mean $\mu_q$ and 
$q$-variance $\sigma_{q}$ can be written as:

\begin{equation}
p(x;\mu_q,\sigma_q)=\frac{1}{\sigma_q {\text B}\left(\frac{\alpha}{2},\frac{1}{2}\right)}
\sqrt{
\frac{|Z|}{u^{(1+1/Z)}}
}
\label{pdf}
\end{equation}
where  $Z=(q-1)/(3-q)$,
%\vskip .4 cm
\begin{equation*}
\alpha=\left\{
\begin{array}{ll}
1-1/Z& \textrm{if  $q<1$}, \\
1/Z  & \textrm{if $1<q<3$}, \\
\end{array}\right.
\end{equation*}
 
$u(x)= 1+Z (x-\mu_q)^2 /  \sigma^{2}_{q}  $, and $\text B(a,b)$ is the  Beta function 

\footnote[1]{
         Beta function:$\text B(a,b) = \int_{0}^{1} t^{a-1}(1-t)^{b-1}dt.$
	}.
	
In the limit of $q\rightarrow 1$ a $q$PDF tends to a standard Gaussian distribution. 
For $q < 1$, it is a compact support distribution, with $x \in [ \pm\sigma_q / \sqrt{-Z}]$. When $1 < q < 3$,  
it is a heavy tail. In the last case, a power law asymptotic behaviour describes well this class of distribution.

Given $X=(x_1,x_2,...x_n)$ a random variable, the cumulative distribution function ($q$CDF), $F(x)=P[X < x]$

\begin{equation*}\label{csum}
F(x) = \int_{-\infty}^{x}p(v)dv,
\end{equation*}

could be represented through $\text I_{w}(a,b)$, the regularized incomplete Beta function

\footnote[2]{
 	Incomplete Beta function:
 	$\text B_{w}(a,b) = \int_{0}^{w} t^{a-1}(1-t)^{b-1}dt$
 	and the regularized incomplete Beta function: $\text I_{w}(a,b) = \text B_{w}(a,b)/\text B(a,b)$
 	}

\begin{equation}
\label{cdf}
F(x;\mu_q;\sigma_q) = \left\{
\begin{array}{ll}
\frac{1}{2} \text I_{\beta}\left(\frac{\alpha}{2},\frac{1}{2}\right) & \textrm{if  $x<\mu_q$}, \\
1-\frac{1}{2} \text I_{\beta}\left(\frac{\alpha}{2},\frac{1}{2}\right) & \textrm{if  $x> \mu_q$}, \\
\end{array}\right.
\end{equation}

where

\begin{equation*}
\beta=\left\{
\begin{array}{ll}
u(x) & \textrm{if  $q<1$}, \\
1/u(x) & \textrm{if $1<q<3$}. \\
\end{array}\right.
\end{equation*}

In third, the quantile function ($q$QF) is obtained as an inverse function of $y=F(x)$, 
$w=\text I^{-1}_{2y}(\frac{\alpha}{2},\frac{1}{2})$: 

\begin{equation}\label{qdf}
C(y;\mu_q,\sigma_q) = \left\{
\begin{array}{ll}
\mu_q-\sigma_q^2 \sqrt{\left( \gamma -1\right )  /Z} & \textrm{if  $y<1/2$}, \\
\mu_q + \sigma_q^2 \sqrt{\left( \gamma -1\right )  /Z} & \textrm{if $1-y<1/2$}, \\
\end{array}\right.
\end{equation}
where

\begin{equation*}
\gamma=\left\{
\begin{array}{ll}
\text I^{-1}_{2y}\left(\frac{\alpha}{2},\frac{1}{2}\right) & \textrm{if  $q<1$}, \\
1/\text I^{-1}_{2y}\left(\frac{\alpha}{2},\frac{1}{2}\right) & \textrm{if $1<q<3$}. \\
\end{array}\right.
\end{equation*}


It is worth calling attention despite the fact that $q$CDF and $q$QF obtained from a compact support distribution do 
not appear explicitly shown in  [@H14], these could be deduced by the same straightforward method presented in it. 


The random numbers generator from a $q$PDF can be implemented in different ways. The straightforward method use the 
quantile function to creates random sample elements $x_i=C(y_i;\mu_q,\sigma_q)$, where $y_i \in [0,1]$ are obtained from 
a uniform random number. In the second way, we use the Box-Muller algorithm as presented in \cite{TNT07} with 
the Mersenne-Twister algorithm as a uniform random number generator to create a $q$-Gaussian random variable
$X\equiv N_q(\mu_q,\sigma_q) \equiv \mu_q+\sigma_q N_q(0,1)$  where $N_q(0,1)$ is called standard $q$-Gaussian.

The classical kurtosis methods, when applied to a data set, are very sensitive to outlying values, however, it is 
possible to diminish this problem at a measurement of the tail heaviness by using robust statistic concepts. To doing that,
given a sorted sample $\{x_1< \dots < \tilde{x}< \dots < x_n\}$ from a univariate distribution with median $\tilde x$,
[@BHS06] established the medcouple to evaluates the tail weight  when applied to $\{x_{1} < \dots < \tilde{x}\}$ and 
$\{\tilde{x}< \dots < x_n\}$. This procedure can be applied to characterize the $q$-Gaussian with heavy tail and 
compact support. To this end, [@santahelena] 
aiming to identify a $q$-Gaussian distribution at empirical data, proposed a relationship between medcouple and $q$ value obtained by curve fitting. 
  

The main goal of the package \pkg{qGaussian} it is lets us to compute $q$PDF (\ref{pdf}), $q$CDF (\ref{cdf}) 
and $q$QF (\ref{qdf}) as same time generates random numbers from a $q$-Gaussian distribution parametrised by $q$ value. 
To compute the Beta function and its inverse it is necessary the 
\pkg{zipfR} package and \pkg{robustbase} is the package of robust statistic to implement a tail weight measurement. 


\begin{table}[!h]
\begin{center}
\begin{tabular}{cc}
		\toprule
 Quantity &  R's commands   \\	
\midrule
$ p(x) $ & \code{ dqgauss(x,q,mu,sig) }  \\
$F(x) $  & \code{pqgauss(x,q,mu,sig,lower.tail=T)}   \\
$C(y)$ & \code{cqgauss(y,q,mu,sig,lower.tail=T) }    \\
$x_{i}$ & \code{rqgauss(n,q,mu,sig,meth="Box-Muller")} \\
$q $ & \code{qbymc(X)} \\
\bottomrule
\end{tabular}
\end{center}
%\vskip -.5 cm
\caption{Sintaxe of R's commands for each output quantities}
\label{tab}
\end{table}

In table \ref{tab}, the input argument \code{x} represent a vector of quantiles for instructions \code{dqgauss(x,..)} and
\code{pqgauss(x,..)} while \code{y} represent a vector of probabilities and \code{n} the length sample, for the random 
number generator. The parameters \code{q}, \code{mu} and \code{sig} are the entropic index, 
$q$-mean and $q$-variance, respectively,
assuming the default values $(0,0,1)$. The medcouple is used into the \code{qbymc(X)} code to estimate $q$ 
value and standard error, receiving a random variable \code{X}, from the class "vector",  as input.
We will see below, all the R's commands described above.


The `qGaussian` is an R package that contain probability distributions functions and others mathematical functions related 
to the Tsallis Statistics [@tsallis]. The user can apply a statistical test to verify how the q-Gaussian distribution adjusts 
to the empirical data [@santahelena]. By default it is provided the density, distribution function, quantile function and 
random generation [@thistleton] for the q-Gaussian distribution. 
A full text [@full] can be find in https://arxiv.org/abs/1703.06172
  

# References
