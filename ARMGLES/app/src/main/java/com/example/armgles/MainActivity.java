package com.example.armgles;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.widget.TextView;
import android.util.Log;

public class MainActivity extends AppCompatActivity {

    private static String LOGTAG = "GraphicsSetup";
    protected GL_View gl_view;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        Log.i(LOGTAG, "Creating New Tutorial View");
        gl_view = new GL_View(getApplication());
        setContentView(gl_view);
        // Example of a call to a native method
//        TextView tv = findViewById(R.id.sample_text);
//        tv.setText(stringFromJNI());
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */

    public native String stringFromJNI();
}

