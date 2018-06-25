
void test_filter(void)
{
	Neighbor node_1;
        node_1.mIncomingLink.mAverage = 10;
        node_1.mOutgoingLink.mAverage = 0;
        FirstOrderFilter(&node_1, 300,0);
        FirstOrderFilter(&node_1, 300,1);

        printf("%i\n",node_1.mIncomingLink.mAverage);
        printf("%i\n",node_1.mOutgoingLink.mAverage);
}
