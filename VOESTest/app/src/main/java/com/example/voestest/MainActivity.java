package com.example.voestest;

import androidx.appcompat.app.AppCompatActivity;

import android.annotation.SuppressLint;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.EditText;
import android.widget.TextView;


public class MainActivity extends AppCompatActivity {

    public static final String EXTRA_MESSAGE = "com.example.voestest.MESSAGE";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }

    /* Called when the user taps the Send button*/
    public void sendMessage(View view)
    {
        //Do something in response to button
        Intent intent = new Intent(this, DisplayMessageActivity.class);
        @SuppressLint("WrongViewCast") TextView editText = (TextView) findViewById(R.id.editText);
        editText.setText(stringFromJNI());
        String message = editText.getText().toString();
        intent.putExtra(EXTRA_MESSAGE, message);
        startActivity(intent);
    }

    public native String stringFromJNI();

    static{
        System.loadLibrary("native-lib");
    }
}
