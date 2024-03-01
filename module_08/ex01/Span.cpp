/* int min=a[0],ans=0;
for (int i=1;i<n;i++)
    if (a[i]<min) min=a[i];
    else ans=max(ans,a[i]-min);
return ans; */

#include "Span.hpp"

template<typename T>
Span::Span() : N(0) {}