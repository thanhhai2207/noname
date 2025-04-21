@extends('layouts.master')

@section('content')
    <div class="container">
        <h1>{{ $magazine->title }}</h1>
        <p><strong>Số phát hành:</strong> {{ $magazine->issue_number }}</p>
        <p><strong>Ngày phát hành:</strong> {{ $magazine->release_date }}</p>
        <p><strong>Đề tài:</strong> {{ $magazine->topic }}</p>
        <p><strong>Nhà xuất bản:</strong> {{ $magazine->publisher->name }}</p>

        <hr>

        <h2>Các tạp chí cùng nhà xuất bản</h2>
        <div class="row">
            @foreach($relatedMagazines as $relatedMagazine)
                <div class="col-md-4">
                    <div class="card mb-4">
                        <div class="card-body">
                            <h5 class="card-title">{{ $relatedMagazine->title }}</h5>
                            <p class="card-text">{{ $relatedMagazine->topic }}</p>
                            <p class="card-text"><small class="text-muted">Ngày phát hành: {{ $relatedMagazine->release_date}}</small></p>
                            <a href="{{ route('magazines.show', $relatedMagazine->id) }}" class="btn btn-info">Xem chi tiết</a>
                        </div>
                    </div>
                </div>
            @endforeach
        </div>
    </div>
@endsection
