
    for(int i = 1; i <= N; i++) {
        for(int weight = 0; weight <= K; weight++) {
            if(input_v[i].first <= weight) {
                if(input_v[i].second + arr[i-1][weight - input_v[i].first] > arr[i-1][weight]) {
                    arr[i][weight] = input_v[i].second + arr[i-1][weight - input_v[i].first];
                } else {
                    arr[i][weight] = arr[i-1][weight];
                }
            } else {
                arr[i][weight] = arr[i-1][weight];
            }
        }
    }

