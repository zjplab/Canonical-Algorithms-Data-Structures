int partition(vector<int> &vi, int low, int up)
{
	int pivot = vi[up];
	int i = low-1;
	for (int j = low; j < up; j++)
	{
		if(vi[j] <= pivot)
		{
			i++;
			swap(vi[i], vi[j]);
		}
	}
	swap(vi[i+1], vi[up]);
	return i+1;
}

void quickSort(vector<int> &vi, int low, int up)
{
	if(low < up)
	{
		int mid = partition(vi, low, up);
		//Watch out! The mid position is on the place, so we don't need to consider it again.
		//That's why below is mid-1, not mid! Otherwise it will occur overflow error!!!
		quickSort(vi, low, mid-1);
		quickSort(vi, mid+1, up);
	}
}
