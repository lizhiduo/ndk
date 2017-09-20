package com.example.lizd.ndk;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity implements View.OnClickListener{

    private boolean isrun = false;
    final private String TAG = "test_dev";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }

    @Override
    public void onClick(View view) {
        switch (view.getId()){
            case R.id.btn :
                if(!isrun){

                    new MyThread().start();
                }else{
                    Log.d(TAG, "Thread is runing...");
                    Toast.makeText(this, "is reading, please wait...", Toast.LENGTH_LONG).show();
                }
                break;

        }
    }

    private class MyThread extends Thread{
        @Override
        public void run() {
            isrun = true;
            jniUtils.test();
            isrun = false;
        }
    }
}
